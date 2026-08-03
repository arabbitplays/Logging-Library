#ifndef DESKTOP_MANAGER_LOGCONFIGURATION_HPP
#define DESKTOP_MANAGER_LOGCONFIGURATION_HPP
#include <logging/targets/Target.hpp>
#include <vector>

namespace Logging
{
    struct LogConfiguration
    {
        friend class LogConfigurationBuilder;

        std::vector<TargetHandle> getTargets()
        {
            return targets;
        }

    private:
        std::vector<TargetHandle> targets;
    };

    using LogConfigurationHandle = std::shared_ptr<LogConfiguration>;
} // namespace Logging

#endif // DESKTOP_MANAGER_LOGCONFIGURATION_HPP