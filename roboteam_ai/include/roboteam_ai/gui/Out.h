//
// Created by Martin Miksik on 25/04/2023.
//

#ifndef RTT_OUT_H
#define RTT_OUT_H

#include <span>

#include "proto/GUI.pb.h"
#include "roboteam_utils/Vector2.h"

namespace rtt::ai::gui {

/**
 * @brief Class for sending data to the interface.
 *
 * The name out is used in analogy to the C++ standard library std::cout or System.out in Java.
 */
class Out {
   public:
    /**
     * @brief Struct representing the parameters for drawing on the interface canvas.
     */
    struct DrawArgs {
        std::basic_string<char> label;
        proto::Drawing::Color color = proto::Drawing::WHITE;
        proto::Drawing::Method method = proto::Drawing::DOTS;
        proto::Drawing::Category category = proto::Drawing::DEBUG;
        int forRobotId = -1;
        int retainForTicks = 10;
        int size = 4;
        int thickness = 4;
    };

    /**
     * @brief Draws a series of points on the interface canvas.
     *
     * @param args The DrawArgs object specifying the drawing parameters.
     * @param points A span of Vector2 points to be drawn.
     */
    static void draw(const DrawArgs& args, std::span<Vector2> points);

    /**
     * @brief Reports a numerical metric to be displayed on the interface.
     *
     * @param label The label for the metric.
     * @param value The numerical value to be reported.
     * @param unit The unit of measurement for the value.
     */
    static void decimal(std::basic_string<char> label, double value, std::basic_string<char> unit = "");

    static void bounded(std::basic_string<char> label, double value, double min, double max, std::basic_string<char> unit = "");

    /**
     * @brief Consumes the visualizations generated by the interface and provides them to the specified consumer function.
     * After consuming, the visualizations are cleared.
     *
     * @param consumer The function that will consume the visualizations.
     */
    static void consumeVisualizations(std::function<void(const proto::MsgToInterface::VisualizationBuffer& visualizations)> consumer);

   private:
    /**
     * @brief Initializes a new drawing on the interface canvas with the specified parameters.
     * Returns a pointer to the created Drawing object.
     *
     * @param args The DrawArgs object specifying the drawing parameters.
     * @return Pointer to the created Drawing object.
     */
    static proto::Drawing* initDrawing(const DrawArgs& args);
    static proto::MsgToInterface::VisualizationBuffer* visualizations;
    static google::protobuf::Arena arena;
};

}  // namespace rtt::ai::gui

#endif  // RTT_OUT_H
