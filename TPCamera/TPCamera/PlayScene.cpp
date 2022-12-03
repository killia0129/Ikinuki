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
}

PlayScene::~PlayScene()
{
}

void PlayScene::ALL()
{
    while (!CheckHitKey(KEY_INPUT_ESCAPE))
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




        stage->Draw();
        aim->Draw(false);
        player->Draw();
        for (auto ptr : obstructs)
        {
            ptr->Draw();
        }

        DrawFormatString(10, 100, GetColor(255, 255, 255), "size:%d", obstructs.size());

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
