#pragma once
#include <string>
class Kd3DDevice
{
public:
	struct DeviceParam
	{
		int windowSizeW = 1280;
		int windowSizeH = 720;
		bool isFullScreen = false;
		bool isDebug = true;
		std::string errMsg = "";
	};

	// デバイスの作成やスワップチェインの作成
	bool Create(
		const HWND& hWnd, int w, int h,
		bool isFullScreen, bool isDebug,
		std::string& resultErrMes);

private:
	//スワップチェイン
	ComPtr<IDXGISwapChain> m_cpGISwapChain = nullptr;

	HWND	m_hWnd;

	// デバイス関連
	ComPtr<ID3D11Device>			m_cpDevice = nullptr;            // 作成関係
	ComPtr<ID3D11DeviceContext>		m_cpDeviceContext = nullptr;     // 描画関係


	//Singleton

public:
	static Kd3DDevice& GetInstance()
	{
		static Kd3DDevice instance;
		return instance;
	}
private:
	Kd3DDevice() {}
	~Kd3DDevice() {}
};
