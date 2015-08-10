#pragma once

#include <d3d12.h>
#include <dxgi1_4.h>
#include <wrl.h>

#include "WindowManager.h"

using namespace Microsoft::WRL;

class DX12Device
{
public:
  DX12Device(bool debug = false);
  ~DX12Device();

  void Render();

  static ComPtr<ID3D12Device> GetDevice();

  static const UINT FrameCount = 2;

  // Pipeline objects.
  ComPtr<IDXGISwapChain3> m_swapChain;
  static ComPtr<ID3D12Device> m_device;
  ComPtr<ID3D12Resource> m_renderTargets[FrameCount];
  ComPtr<ID3D12CommandAllocator> m_commandAllocator;
  ComPtr<ID3D12CommandQueue> m_commandQueue;
  ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
  ComPtr<ID3D12PipelineState> m_pipelineState;
  ComPtr<ID3D12GraphicsCommandList> m_commandList;
  UINT m_rtvDescriptorSize;

  // Synchronization objects.
  UINT m_frameIndex;
  HANDLE m_fenceEvent;
  ComPtr<ID3D12Fence> m_fence;
  UINT64 m_fenceValue;
};
