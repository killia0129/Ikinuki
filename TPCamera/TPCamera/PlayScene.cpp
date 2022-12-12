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
    time = 45.0f;
    plusSec = 0;
    plusSecX = 0;
    plusSecY = 0;
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
        time -= deltaTime;
        //AddSpeed(deltaTime);


        srand(seed);



        if (obsCool > 3.0f)
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
            if (ptr->posGetter().z < -10.0f)
            {
                ptr->setDead(true);
            }
        }
        if (plusSec == 1)
        {
            if (plusSecY > 20)
            {
                plusSecY -= 1000 * deltaTime;
            }
            else
            {
                plusSecY = 20;
                plusSec = 2;
            }
        }
        if (plusSec == 2)
        {
            if (plusSecX <= 1910)
            {
                plusSecX += 1000 * deltaTime;
            }
            else
            {
                plusSec = 0;
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
            if (dis < 3.0f&&ptr->posGetter().z>10.0f)
            {
                ptr->GivenDmg(deltaTime);
                Particle* newEffect = new Particle(ptr->posGetter());
                particle.emplace_back(newEffect);
                if (ptr->isDead())
                {
                    if (ptr->TypeGetter() == ObstructBase::TYPE::METEOR)
                    {
                        time += 5.0f;
                        if (time > 60.0f)
                        {
                            time = 60.0f;
                        }
                        if (plusSec == 0)
                        {
                            plusSec = 1;
                            plusSecX = ConvWorldPosToScreenPos(ptr->posGetter()).x;
                            plusSecY = ConvWorldPosToScreenPos(ptr->posGetter()).y;
                        }
                    }
                    deleteCount++;
                }
            }
        }
        for (auto _ptr : particle)
        {
            _ptr->Update(deltaTime);
        }
        for (auto ptr : expro)
        {
            ptr->Update(deltaTime);
        }

        ui->Update(time, deleteCount);

        //Delete
        std::vector<ObstructBase*>deadObs;
        for (auto ptr : obstructs)
        {
            if (ptr->isDead())
            {
                EntryExp(ptr->posGetter());
                deadObs.emplace_back(ptr);
            }
        }

        std::vector<Exprosion*>deadExp;
        for (auto ptr : expro)
        {
            if (ptr->isEnd())
            {
                deadExp.emplace_back(ptr);
            }
        }
        std::vector<Particle*>deadPart;
        for (auto ptr : particle)
        {
            if (ptr->isEnd())
            {
                deadPart.emplace_back(ptr);
            }
        }


        for (auto ptr : deadObs)
        {
            ObsDelete(ptr);
        }
        for (auto ptr : deadExp)
        {
            ExpDelete(ptr);
        }
        for (auto ptr : deadPart)
        {
            PartDelete(ptr);
        }




        stage->Draw();
        aim->Draw(false);
        for (auto ptr : expro)
        {
            ptr->Draw();
        }
        player->Draw();
        for (auto ptr : obstructs)
        {
            ptr->Draw();
        }
        
        for (auto ptr : particle)
        {
            ptr->Draw();
        }

        if (plusSec != 0)
        {
            SetFontSize(20);
            DrawString(plusSecX, plusSecY, "+5.0s", GetColor(255, 255, 255));
            SetFontSize(40);
        }

        ui->Draw();

        /*for (int i = 0; i < (30 - deleteCount); i++)
        {
            DrawBox(i * 64 + 2, 5, i * 64 + 62, 65,GetColor(255, 255, 255), true);
        }

        float timeRatio = time / 60.0f;

        DrawBox(2, 70, 2 + (1916 * timeRatio), 130, GetColor(255, 255 * timeRatio, 255 * timeRatio), true);*/

        //DrawFormatString(10, 100, GetColor(255, 255, 255), "残り　%d　個！",30 - deleteCount);

        if (deleteCount >= 30)
        {
            float num = 0.0f;
            while (num <= 1100.0f)
            {
                DrawBox(0, 0, 1920, num, GetColor(0, 0, 0), true);
                num += 4.0f;
                ScreenFlip();
            }
            //WaitTimer(1000);
            return count;
        }

        if (time < 0)
        {
            float num = 0.0f;
            while (num <= 1100.0f)
            {
                DrawBox(0, 0, 1920, num, GetColor(0, 0, 0), true);
                num += 4.0f;
                ScreenFlip();
            }
            //WaitTimer(1000);
            return -4.0f;
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

void PlayScene::EntryExp(VECTOR pos)
{
    Exprosion* newObj = new Exprosion(pos);
    expro.emplace_back(newObj);
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

void PlayScene::ExpDelete(Exprosion* deleteExp)
{
    auto iter = std::find(expro.begin(), expro.end(), deleteExp);
    if (iter != expro.end())
    {
        std::iter_swap(iter, expro.end() - 1);
        expro.pop_back();
    }
}

void PlayScene::PartDelete(Particle* deletePart)
{
    auto iter = std::find(particle.begin(), particle.end(), deletePart);
    if (iter != particle.end())
    {
        std::iter_swap(iter, particle.end() - 1);
        particle.pop_back();
    }
}
