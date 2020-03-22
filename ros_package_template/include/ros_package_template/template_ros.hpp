#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>

#include <msg_package_template/Template.h>
#include <msg_package_template/TemplateService.h>
#include <lib_package_template/template.hpp>

namespace ariitk::ros_package_template {

class TemplateROS {
    public:
        TemplateROS()
            : cloud_(new pcl::PointCloud<pcl::PointXYZ>) {};
        void init(ros::NodeHandle& nh);
        void run();

    private:
        void cloudCallback(const sensor_msgs::PointCloud2& msg);
        bool serviceCallback(msg_package_template::TemplateService::Request& req, msg_package_template::TemplateService::Response& resp);

        ros::Publisher pc_fit_pub_;
        ros::Publisher model_pub_;

        ros::Subscriber pc_sub_;

        ros::ServiceServer plane_flag_server_;

        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_;

        ariitk::lib_package_template::ChildTemplatePlane plane_;
        ariitk::lib_package_template::ChildTemplateSphere sphere_;

        bool do_plane_;
};

} // namespace ariitk::ros_package_template