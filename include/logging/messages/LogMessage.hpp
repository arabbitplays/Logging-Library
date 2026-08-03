#ifndef DESKTOP_MANAGER_LOGMESSAGE_HPP
#define DESKTOP_MANAGER_LOGMESSAGE_HPP
#include "Severity.hpp"
#include "SourcePath.hpp"
#include "Timestamp.hpp"

#include <string>
#include <utility>

namespace Logging
{
    struct LogMessage
    {
        LogMessage(SourcePath path, const Severity severity, std::string message)
            : timestamp(std::chrono::system_clock::now()), source_path(std::move(path)), severity(severity),
              message(std::move(message))
        {
        }

        Timestamp timestamp;
        SourcePath source_path;
        Severity severity;
        std::string message;
    };

    using LogMessageHandle = std::shared_ptr<LogMessage>;
} // namespace Logging

#endif // DESKTOP_MANAGER_LOGMESSAGE_HPP