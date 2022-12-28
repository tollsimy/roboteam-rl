//
// Created by alexander on 19-04-22.
//
#include <gtest/gtest.h>

#include "helpers/FieldHelper.h"
#include "helpers/WorldHelper.h"
#include <roboteam_utils/Field.hpp>
#include "world/FieldComputations.h"
#include "world/World.hpp"

TEST(FieldHelperTests, DefenseAreaTest) {
    using namespace rtt::ai;
    auto protoField = testhelpers::FieldHelper::generateField();
    auto protoWorld = testhelpers::WorldHelper::getWorldMsg(11, 11, true, protoField);
    auto const& [_, world] = rtt::world::World::instance();
    world->updateWorld(protoWorld);
    world->updateField(protoField);

    auto field = world->getField().value();
    auto fieldLength = field.playArea.width();
    auto defAreaDepth = field.leftDefenseArea.topRight().x - field.leftGoalArea.rightLine().center().x;
    auto defAreaWidth = field.leftDefenseArea.topLeft().y;

    EXPECT_TRUE(FieldComputations::pointIsInOurDefenseArea(field, rtt::Vector2(-fieldLength * 0.49, 0)));
    EXPECT_TRUE(FieldComputations::pointIsInTheirDefenseArea(field, rtt::Vector2(fieldLength * 0.49, 0)));

    EXPECT_FALSE(FieldComputations::pointIsInTheirDefenseArea(field, rtt::Vector2(fieldLength * 0.5 - defAreaDepth * 1.01, 0)));
    EXPECT_FALSE(FieldComputations::pointIsInOurDefenseArea(field, rtt::Vector2(fieldLength * 0.5 + defAreaDepth * 1.01, 0)));

    EXPECT_TRUE(FieldComputations::pointIsInOurDefenseArea(field, rtt::Vector2(-fieldLength * 0.5 + defAreaDepth * 0.9, 0)));
    EXPECT_TRUE(FieldComputations::pointIsInTheirDefenseArea(field, rtt::Vector2(fieldLength * 0.5 - defAreaDepth * 0.9, 0)));

    EXPECT_TRUE(FieldComputations::pointIsInOurDefenseArea(field, rtt::Vector2(-fieldLength * 0.5 + defAreaDepth * 0.5, defAreaWidth * 0.99)));
    EXPECT_TRUE(FieldComputations::pointIsInTheirDefenseArea(field, rtt::Vector2(fieldLength * 0.5 - defAreaDepth * 0.5, defAreaWidth * 0.99)));

    EXPECT_FALSE(FieldComputations::pointIsInOurDefenseArea(field, rtt::Vector2(-fieldLength * 0.5 + defAreaDepth * 0.5, defAreaWidth * 1.01)));
    EXPECT_FALSE(FieldComputations::pointIsInTheirDefenseArea(field, rtt::Vector2(fieldLength * 0.5 - defAreaDepth * 0.5, defAreaWidth * 1.01)));
}

TEST(FieldHelperTests, FieldTest) {
    using namespace rtt::ai;
    auto protoField = testhelpers::FieldHelper::generateField();
    auto protoWorld = testhelpers::WorldHelper::getWorldMsg(11, 11, true, protoField);
    auto const& [_, world] = rtt::world::World::instance();
    world->updateWorld(protoWorld);
    world->updateField(protoField);

    auto field = world->getField().value();
    auto fieldWidth = field.playArea.width();
    auto fieldHeight = field.playArea.height();

    FieldComputations::pointIsInField(field, rtt::Vector2(0.99 * fieldWidth, 0.99 * fieldHeight));
    EXPECT_TRUE(FieldComputations::pointIsInField(field, rtt::Vector2(0.49 * fieldWidth, 0.49 * fieldHeight)));
    EXPECT_TRUE(FieldComputations::pointIsInField(field, rtt::Vector2(-0.49 * fieldWidth, -0.49 * fieldHeight)));

    EXPECT_FALSE(FieldComputations::pointIsInField(field, rtt::Vector2(0.51 * fieldWidth, 0.51 * fieldHeight)));
    EXPECT_FALSE(FieldComputations::pointIsInField(field, rtt::Vector2(-0.51 * fieldWidth, -0.51 * fieldHeight)));
}
