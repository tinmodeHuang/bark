// Copyright (c) 2020 fortiss GmbH
//
// Authors: Julian Bernhard, Klemens Esterle, Patrick Hart and
// Tobias Kessler
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#ifndef BARK_PYTHON_WRAPPER_WORLD_LTL_HPP_
#define BARK_PYTHON_WRAPPER_WORLD_LTL_HPP_

#include "bark/python_wrapper/common.hpp"
#include "bark/world/evaluation/ltl/label_functions/base_label_function.hpp"

namespace py = pybind11;
using namespace bark::world::evaluation;
using namespace bark::world;
using objects::AgentId;

class PyBaseLabelFunction : public BaseLabelFunction {
 public:
  using BaseLabelFunction::BaseLabelFunction;

  bool Evaluate(const ObservedWorld& observed_world, const AgentId& agent_id) const override {
    PYBIND11_OVERLOAD_PURE(bool, BaseLabelFunction, Evaluate,
                           observed_world, agent_id);
  }
};

void python_ltl(py::module m);

#endif  // BARK_PYTHON_WRAPPER_WORLD_LTL_HPP_
