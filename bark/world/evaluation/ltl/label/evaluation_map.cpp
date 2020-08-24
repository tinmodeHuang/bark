// Copyright (c) 2020 fortiss GmbH
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#include "glog/logging.h"

#include "evaluation_map.hpp"

namespace bark {
namespace world {
namespace evaluation {
EvaluationMap::EvaluationMap(const ObservedWorld* world,
                             const std::vector<LabelFunctionPtr>& evaluators)
    : world_(world) {
  for (const auto& elem : evaluators) {
    evaluators_.insert({elem->GetLabelStr(), elem});
  }
}
std::optional<bool> EvaluationMap::GetValue(const Label& label) {
  std::optional<bool> value;
  auto it = values_.find(label);
  if (it == values_.end()) {
    auto eval_it = evaluators_.find(label.GetLabelStr());
    if (eval_it != evaluators_.end()) {
      value = eval_it->second->Evaluate(*world_, label.GetAgentId());
      values_.insert({label, *value});
    }
  } else {
    value = it->second;
  }
  return value;
}
bool EvaluationMap::SetValue(const Label& label, bool value) {
  values_.insert({label, value});
}
void EvaluationMap::SetWorld(const ObservedWorld* world) {
  world_ = world;
  Clear();
}
void EvaluationMap::Clear() { values_.clear(); }
}  // namespace evaluation
}  // namespace world
}  // namespace bark
