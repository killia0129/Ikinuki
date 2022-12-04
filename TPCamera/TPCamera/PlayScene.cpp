#include "PlayScene.h"

PlayScene::PlayScene()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cell[i][j] = VGet(-15.0+10.0f * (float)i, -15.0 + 10.0f* (float)j, 500.0f);
        }
    }
    seed = 0;
    nowTime = GetNowCount();
    previousTime = GetNowCount();
    count = 0.0f;
    obsCool = 0.0f;
    deltaTime = 0.0f;
    deleteCount = 0;
}

PlayScene::~PlayScene()
{
}

float PlayScene::ALL()
{
    while (1)
    {
        ClearDrawScreen();


        nowTime = GetNowCount();
        deltaTime = (float)(nowTime - previousTime) / 1000.0f;
        count += deltaTime;
        obsCool += deltaTime;


        srand(seed);



        if (obsCool > 1.0f)
        {
            Entry();
            obsCool = 0.0f;
        }
        seed++;
        if (seed > 100000)
        {
            seed = 0;
        }
        previousTime = nowTime;


        
        //Update
        for (auto ptr : obstructs)
        {
            ptr->Update(deltaTime);
        }
        stage->Update(deltaTime);
        player->Update(deltaTime);
        aim->Update(deltaTime, player->posGetter());
        for (auto ptr : obstructs)
        {
            if (ptr->posGetter().z < 0.0f)
            {
                ptr->setDead(true);
            }
        }

        //Hit
        VECTOR mark = aim->MarkGetter();
        for (auto ptr : obstructs)
        {
            float obsZ = ptr->posGetter().z;
            float ratio = (obsZ - 3.0f) / (mark.z - 3.0f);
            float moveX = player->posGetter().x + ((mark.x - player->posGetter().x) * ratio);
            float moveY = player->posGetter().y + ((mark.y - player->posGetter().y) * ratio);
            VECTOR markMoved = VGet(moveX, moveY, ptr->posGetter().z);
            float dis = (ptr->posGetter().x - markMoved.x) * (ptr->posGetter().x - markMoved.x) +  (ptr->posGetter().y - markMoved.y) * (ptr->posGetter().y - markMoved.y);
            dis = sqrtf(dis);
            if (dis < 2.0f&&ptr->posGetter().z>10.0f)
            {
                ptr->setDead(true);
                deleteCount++;
            }
        }


        //Delete
        std::vector<ObstructBase*>deadObs;
        for (auto ptr : obstructs)
        {
            if (ptr->isDead())
            {
                deadObs.emplace_back(ptr);
            }
        }
        for (auto ptr : deadObs)
        {
            ObsDelete(ptr);
        }




        stage->Draw();
        aim->Draw(false);
        player->Draw();
        for (auto ptr : obstructs)
        {
            ptr->Draw();
        }

        DrawFormatString(10, 100, GetColor(255, 255, 255), "COUNT : %d", deleteCount);

        if (deleteCount >= 10)
        {
            return count;
        }

        if (CheckHitKey(KEY_INPUT_ESCAPE))
        {
            return -1.0f;
        }

        ScreenFlip();
    }
}

void PlayScene::Entry()
{
    int type = rand() % 2;
    int cellX, cellY;

    if (type == 0)
    {
        cellY = rand() % 4;
        int wave = rand() % 2;
        if (wave == 0)
        {
            cellX = rand() % 2;
            Meteor* newObj = new Meteor(cell[cellX][cellY], true);
            obstructs.emplace_back(newObj);
        }
        else
        {
            cellX = rand() % 4;
            Meteor* newObj = new Meteor(cell[cellX][cellY], false);
            obstructs.emplace_back(newObj);
        }
    }
    else
    {
        cellX = rand() % 4;
        cellY = rand() % 4;
        Needle* newObj = new Needle(cell[cellX][cellY]);
        obstructs.emplace_back(newObj);
    }
}

void PlayScene::ObsDelete(ObstructBase* deleteObs)
{
    auto iter = std::find(obstructs.begin(), obstructs.end(), deleteObs);
    if (iter != obstructs.end())
    {
        std::iter_swap(iter, obstructs.end() - 1);
        obstructs.pop_back();
    }
}
