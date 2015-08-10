#pragma once

#include "DX12Device.h"

class DX12Device;

class CommandList
{
public:
  CommandList(DX12Device * device);
  ~CommandList();

  void Reset();
  void Close();

private:
  DX12Device * device_;
  ComPtr<ID3D12GraphicsCommandList> commandlist_;
};
