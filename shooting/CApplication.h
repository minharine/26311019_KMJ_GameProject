#pragma once
class CApplication
{
public:
	int Init();
	int Update();
	int Render();
	int Destroy();

protected:
	int InitSdk();

protected:
	// windows
	POINT m_winPos{ 100, 100 };
	SIZE m_WinSize{ 800, 600 };
	std::string m_WinName = "sacrosanct";
};

