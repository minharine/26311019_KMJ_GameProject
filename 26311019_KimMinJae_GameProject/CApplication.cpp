#include <stdio.h>
#include "CApplication.h"
#include "glc2d.h"

int AppUpdate()
{
    return g_app.Update();
}

int AppRender()
{
    return g_app.Render();
}

extern CApplication g_App;

int CApplication::Init()
{
    InitSdk();

    m_sceneBegin.Init();

    return true;
}

int CApplication::Update()
{
    if (m_scene == SceneType::BEGIN)
    {
        m_sceneBegin.Update();
    }
    else if (m_scene == SceneType::PLAY)
    {
        m_scenePlay.Update();
    }
    return 0;
}

int CApplication::Render()
{
    if (m_scene == SceneType::BEGIN)
    {
        m_sceneBegin.Render();
    }
    else if (m_scene == SceneType::PLAY)
    {
        m_scenePlay.Render();
    }
    return 0;
}

int CApplication::Destroy()
{
    if (m_scene == SceneType::BEGIN)
    {
        m_sceneBegin.Destroy();
    }
    else if (m_scene == SceneType::PLAY)
    {
        m_scenePlay.Destroy();
    }
    return 0;
}

SIZE CApplication::GetWinSize()
{
    return SIZE();
}

int CApplication::InitSdk()
{
    g2_InitSdk();

    g2_SetFrameMove(AppUpdate);
    g2_SetRender(AppRender);

    g2_CreateWin(m_winPos.x, m_winPos.y,
                 m_winSize.cx, m_winSize.cy,
                 m_winName.c_str());

    return 0;
}
