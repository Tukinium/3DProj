#pragma once
class KdTexture
{
public:
	bool Create(ID3D11Texture2D* pTexBuffer);

	inline ID3D11RenderTargetView* RTV()const {
		return m_cpRTV.Get();
	}
	inline ID3D11RenderTargetView* const* RTVAddress()const {
		return m_cpRTV.GetAddressOf();
	}

private:
	bool CreateRTV();
	ComPtr<ID3D11Texture2D>m_cpBuffer = nullptr;
	D3D11_TEXTURE2D_DESC m_info = {};
	ComPtr<ID3D11RenderTargetView>m_cpRTV = nullptr;

};