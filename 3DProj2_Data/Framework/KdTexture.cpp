#include "KdTexture.h"

bool KdTexture::Create(ID3D11Texture2D* pTexBuffer)
{
	if (pTexBuffer == nullptr)return false;
	m_cpBuffer = pTexBuffer;

	pTexBuffer->GetDesc(&m_info);
	return CreateRTV();
}

bool KdTexture::CreateRTV()
{
	if (m_cpBuffer == nullptr)return false;
	CD3D11_RENDER_TARGET_VIEW_DESC rtvDesc = {};
	rtvDesc.Format = m_info.Format;
	rtvDesc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
	HRESULT hr = Kd3DDevice::GetInstance().GetDevice()->
		CreateRenderTargetView(m_cpBuffer.Get(), &rtvDesc, &m_cpRTV);
	if (FAILED(hr))
	{
		assert(0 && "RenderTargetViewì¬¸”s");
		return false;
	}

	return true;
}
