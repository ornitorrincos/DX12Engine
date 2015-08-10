#include "DX12Device.h"
#include "CommandList.h"

CommandList::CommandList(DX12Device * device) : device_(device)
{
  device_->m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, device_->m_commandAllocator.Get(), nullptr, IID_PPV_ARGS(&device_->m_commandList));
  Close();
}

CommandList::~CommandList()
{

}

void CommandList::Reset()
{
  commandlist_->Reset(device_->m_commandAllocator.Get(), device_->m_pipelineState.Get());
}

void CommandList::Close()
{
  commandlist_->Close();
}
