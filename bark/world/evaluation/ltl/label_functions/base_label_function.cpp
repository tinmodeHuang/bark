// Copyright (c) 2020 fortiss GmbH
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#include "bark/world/evaluation/ltl/label_functions/base_label_function.hpp"

#include "bark/world/observed_world.hpp"

namespace bark {
namespace world {
namespace evaluation {
bool BaseLabelFunction::Evaluate(const world::ObservedWorld& observed_world,
                                 const AgentId& agent_id) const {
    return EvaluateAgent(observed_world, observed_world.GetAgent(agent_id));
}
}
}  // namespace world
}  // namespace bark
