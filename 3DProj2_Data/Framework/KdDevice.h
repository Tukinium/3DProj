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

	// �f�o�C�X�̍쐬��X���b�v�`�F�C���̍쐬
	bool Create(
		const HWND& hWnd, int w, int h,
		bool isFullScreen, bool isDebug,
		std::string& resultErrMes);

private:
	//�X���b�v�`�F�C��
	ComPtr<IDXGISwapChain> m_cpGISwapChain = nullptr;

	HWND	m_hWnd;

	// �f�o�C�X�֘A
	ComPtr<ID3D11Device>			m_cpDevice = nullptr;            // �쐬�֌W
	ComPtr<ID3D11DeviceContext>		m_cpDeviceContext = nullptr;     // �`��֌W


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
