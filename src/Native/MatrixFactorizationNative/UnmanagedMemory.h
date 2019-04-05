// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

#pragma once
#include "mf.h"
#include "../Stdafx.h"

using namespace mf;

struct mf_parameter_bridge
{
    int32_t fun;
    int32_t k;
    int32_t nr_threads;
    int32_t nr_bins;
    int32_t nr_iters;
    float lambda_p1;
    float lambda_p2;
    float lambda_q1;
    float lambda_q2;
    float eta;
    float alpha;
    float c;
    uint8_t do_nmf;
    uint8_t quiet;
    uint8_t copy_data;
};

EXPORT_API(void) MFDestroyModel(mf_model *&model);

EXPORT_API(mf_model*) MFTrain(const mf_problem *prob, const mf_parameter_bridge *parameter_bridge);

EXPORT_API(mf_model*) MFTrainWithValidation(const mf_problem *tr, const mf_problem *va, const mf_parameter_bridge *parameter_bridge);
    
EXPORT_API(float) MFCrossValidation(const mf_problem *prob, int nr_folds, const mf_parameter_bridge* parameter_bridge);

EXPORT_API(float) MFPredict(const mf_model *model, int p_idx, int q_idx);
