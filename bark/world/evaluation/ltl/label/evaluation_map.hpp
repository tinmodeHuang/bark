// Copyright (c) 2020 fortiss GmbH
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#ifndef BARK_WORLD_EVALUATION_LTL_LABEL_EVALUATION_MAP_HPP_
#define BARK_WORLD_EVALUATION_LTL_LABEL_EVALUATION_MAP_HPP_

#include <optional>

#include "bark/world/evaluation/ltl/label/label.h"
#include "bark/world/evaluation/ltl/label_functions/base_label_function.hpp"

namespace bark {
namespace world {
namespace evaluation {

class EvaluationMap {
 public:
  EvaluationMap(
      const ObservedWorld* world,
                const std::vector<LabelFunctionPtr>& evaluators);
  std::optional<bool> GetValue(const Label& label);
  std::optional<bool> operator[](const Label& label) {
    return GetValue(label);
  };
  bool SetValue(const Label& label, bool value);
  void SetWorld(const ObservedWorld* world);
  void Clear();

 private:
  const ObservedWorld* world_;
  std::unordered_map<std::string, LabelFunctionPtr> evaluators_;
  std::unordered_map<Label, bool, LabelHash> values_;
};

}  // namespace evaluation
}  // namespace world
}  // namespace bark

#endif  // BARK_WORLD_EVALUATION_LTL_LABEL_EVALUATION_MAP_HPP_
