#include "TitleScene.h"

TitleScene::TitleScene()
{
    nowTime = 0;
    deltaTime = 0.0f;
    previousTime = 0;
    obsCool = 2.5f;
    seed = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cell[i][j] = VGet(-15.0 + 10.0f * (float)i, -15.0 + 10.0f * (float)j, 500.0f);
        }
    }
}

TitleScene::~TitleScene()
{
}

float TitleScene::ALL()
{
    while (1)
    {
        ClearDrawScreen();


        nowTime = GetNowCount();
        deltaTime = (float)(nowTime - previousTime) / 1000.0f;
        obsCool += deltaTime;
        //AddSpeed(deltaTime);


        srand(seed);



        if (obsCool > 2.5f)
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

        for (auto ptr : obstructs)
        {
            if (ptr->posGetter().z < 0.0f)
            {
                ptr->setDead(true);
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
        for (auto ptr : obstructs)
        {
            ptr->Draw();
        }

        DrawFormatString(675, 50, GetColor(0, 255, 0), "Press ENTER to Start");
        SetFontSize(125);
        DrawFormatString(350, 175, GetColor(0, 255, 0), "Endress BEAMer");
        SetFontSize(40);
        DrawFormatString(250, 400, GetColor(0, 255, 0), "W : UP  A : LEFT  S : DOWN  D : RIGHT  Mouse : Aim");


        if (CheckHitKey(KEY_INPUT_ESCAPE))
        {
            return -2.0f;
        }

        if (CheckHitKey(KEY_INPUT_RETURN))
        {
            return -1.0f;
        }

        ScreenFlip();
    }
}

void TitleScene::Entry()
{
    int type = rand() % 2;
    int cellX, cellY;

    if (type == 0)
    {
        cellY = rand() % 4;
        int wave = rand() % 2;
        if (wave == 0)
        {
            cellX = rand() % 2 + 1;
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

void TitleScene::ObsDelete(ObstructBase* deleteObs)
{
    auto iter = std::find(obstructs.begin(), obstructs.end(), deleteObs);
    if (iter != obstructs.end())
    {
        std::iter_swap(iter, obstructs.end() - 1);
        obstructs.pop_back();
    }
}
