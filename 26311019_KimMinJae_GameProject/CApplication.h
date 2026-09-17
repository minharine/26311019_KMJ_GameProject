#pragma once
#include <windows.h>
#include <string>

#include "SceneBegin.h"
#include "ScenePlay.h"

enum class SceneType
{
	BEGIN,
	PLAY
};


class CApplication
{
public:
	int Init();
	int Update();
	int Render();
	int Destroy();

public:
	SIZE GetWinSize();

protected:
	int InitSdk();

protected:
	POINT m_winPos{ 100, 100 };
	SIZE m_WinSize{ 800, 600 };
	std::string m_WinName = "sacrosanct";

	SceneType m_scene = SceneType::BEGIN;

	SceneBegin m_sceneBegin;
	ScenePlay m_scenePlay
};

extern CApplication g_app;

