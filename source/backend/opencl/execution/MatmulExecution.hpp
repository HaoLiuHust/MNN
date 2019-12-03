//
//  MatMulExecution.hpp
//  MNN
//
//  Created by MNN on 2019/01/31.
//  Copyright © 2018, Alibaba Group Holding Limited
//

#ifndef MatMulExecution_hpp
#define MatMulExecution_hpp

#include "Execution.hpp"
#include "core/OpenCLBackend.hpp"
#include "Execution.hpp"
#include "core/OpenCLBackend.hpp"
#include "core/OpenCLRunningUtils.hpp"

namespace MNN {
namespace OpenCL {

class MatMulExecution : public Execution {
public:
    MatMulExecution(const std::vector<Tensor *> &inputs, const MNN::Op *op, Backend *backend);
    virtual ~MatMulExecution() = default;

    virtual ErrorCode onExecute(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs) override;
    virtual ErrorCode onResize(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs) override;

private:
    cl::Kernel mKernel;
    uint32_t mMaxWorkGroupSize;
    std::vector<int> mInput0Shape;
    std::vector<int> mInput1Shape;
    bool mAreadySetArg;
    OpenCLBackend *mOpenCLBackend;
    uint32_t mGlobalWorkSize[2] = {1, 1};
    std::vector<uint32_t> mLocalWorkSize{1, 1, 1, 1};
};

} // namespace OpenCL
} // namespace MNN

#endif 
