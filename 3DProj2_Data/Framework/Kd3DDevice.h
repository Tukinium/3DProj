#pragma once
class KdTexture;

class Kd3DDevice
{
public:
	void Begin();
	void End();

	ID3D11Device* GetDevice()const {
		return m_cpDevice.Get();
	}

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
	std::shared_ptr<KdTexture> m_spBackBuffer = nullptr;

	//スワップチェイン
	ComPtr<IDXGISwapChain> m_cpGISwapChain = nullptr;

	HWND	m_hWnd;

	// デバイス関連
	ComPtr<ID3D11Device>			m_cpDevice = nullptr;            // 作成関係
	ComPtr<ID3D11DeviceContext>		m_cpDeviceContext = nullptr;     // 描画関係

	//初期化カラー
	float m_clearCol[4] = { 1,0,1,1 };

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
