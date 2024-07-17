#pragma once

//ComPtr
#include<wrl/client.h>
using Microsoft::WRL::ComPtr;

//DirectX Lib
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"dxgi.lib")

#include<d3d11.h>
#include<dxgi.h>
#include"Kd3DDevice.h"

#include"KdTexture.h"