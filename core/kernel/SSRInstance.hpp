#pragma once
#include "3rdparty/shadowsocksr-uvw/src/SSRThread.hpp"
#include "QvPluginProcessor.hpp"
#include "common/CommonHelpers.hpp"
#include "utils/HttpProxy.hpp"
namespace SSRPlugin
{
    class SSRKernelInstance : public Qv2rayPlugin::QvPluginKernel
    {
      public:
        explicit SSRKernelInstance(QObject *parent = nullptr);
        bool StartKernel() override;
        bool StopKernel() override;
        void SetConnectionSettings(const QMap<KernelSetting, QVariant> &options, const QJsonObject &settings) override;

      private:
        int socks_local_port;
        int http_local_port;
        bool enable_udp;
        QString listen_address;
        ShadowSocksRServerObject outbound;
        std::unique_ptr<Qv2rayPlugin::Utils::HttpProxy> httpProxy;
        std::unique_ptr<SSRThread> ssrThread;
    };
} // namespace SSRPlugin
