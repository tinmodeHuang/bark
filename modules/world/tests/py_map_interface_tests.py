# Copyright (c) 2019 fortiss GmbH
#
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

import unittest
import filecmp
import matplotlib.pyplot as plt
from bark.world.agent import *
from bark.models.behavior import *
from bark.world import *
from bark.geometry import *
from bark.models.dynamic import *
from bark.models.execution import *
from bark.geometry import *
from bark.geometry.standard_shapes import *
from modules.runtime.commons.parameters import ParameterServer
from bark.world.opendrive import *
from bark.world.map import *
from modules.runtime.commons.xodr_parser import XodrParser


class EnvironmentTests(unittest.TestCase):
    def test_Crossing8Course(self):
        xodr_parser = XodrParser("modules/runtime/tests/data/Crossing8Course.xodr")

        params = ParameterServer()
        world = World(params)

        map_interface = MapInterface()
        map_interface.set_open_drive_map(xodr_parser.map)
        map_interface.set_roadgraph(xodr_parser.roadgraph)
        world.set_map(map_interface)

        start_point = Point2d(0, -11)
        lanes_near_start = map_interface.find_nearest_lanes(start_point, 1)
        assert(len(lanes_near_start) == 1)

        goal_point = Point2d(-191.789,-50.1725)
        lanes_near_goal = map_interface.find_nearest_lanes(goal_point, 1)
        assert(len(lanes_near_goal) == 1)

        (route_inner, route_outer) = map_interface.compute_lane_boundaries_horizon(lanes_near_start[0].lane_id, lanes_near_goal[0].lane_id)

        for l in route_inner:
            assert(l.lane_type == LaneType.driving)
        
        for l in route_outer:
            assert(l.lane_type == LaneType.driving)
        
        #v = map_interface.get_roadgraph().get_vertices()


if __name__ == '__main__':
    unittest.main()