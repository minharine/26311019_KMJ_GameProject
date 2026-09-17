#pragma once

struct Ball
{
    float x;
    float y;
    float vx;
    float vy;
};

class ScenePlay
{
public:
    int Init();
    int Destroy();
    int Update();
    int Render();

private:
    Ball m_ball;
    int m_txBall;
};