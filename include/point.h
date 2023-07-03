#pragma once
#ifndef _POINT_H
#define _POINT_H

#include "config.h"
#include <pcl/io/ply_io.h>

namespace random_ply{
    template<typename CloudType>
    class Point
    {
        public:
        Point(const Config& config_) : m_config(config_) {}
        void CreatePLY() const {
            typename pcl::PointCloud<CloudType>::Ptr cloud(new typename pcl::PointCloud<CloudType>);
            cloud->points.reserve(m_config.size);
            while ( cloud->points.size() < m_config.size )
            {
                const auto point = Create();
                if ( Confirm(cloud, point) ) cloud->points.push_back(point);
            }

            pcl::PLYWriter writer;
            writer.write<CloudType>(m_config.file, *cloud);
        };
        virtual CloudType Create() const { return CloudType(); };
        Config m_config;
        private:
        auto Confirm(const typename pcl::PointCloud<CloudType>::Ptr& cloud, const CloudType& point) const {
            for ( const auto& index : *cloud)
                if ( index.x == point.x && index.y == point.y && index.z == point.z ) return false;
            return true;
        };
    };

    class Mono : public Point<pcl::PointXYZ>{
        public:
        Mono(const Config& config_) : Point<pcl::PointXYZ>(config_) {}
        pcl::PointXYZ Create() const override {
            return pcl::PointXYZ(m_config.Geom(0), m_config.Geom(1), m_config.Geom(2));
        };
    };

    class Color : public Point<pcl::PointXYZRGB>{
        public:
        Color(const Config& config_) : Point<pcl::PointXYZRGB>(config_) {}
        pcl::PointXYZRGB Create() const override {
            return pcl::PointXYZRGB(m_config.Geom(0), m_config.Geom(1), m_config.Geom(2), m_config.Alt(), m_config.Alt(), m_config.Alt());
        };
    };
}

#endif