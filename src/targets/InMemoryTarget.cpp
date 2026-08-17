#include <logging/targets/InMemoryTarget.hpp>
#include <cassert>

namespace Logging
{
    InMemoryTarget::InMemoryTarget(uint32_t buffer_size)
    {
        assert(buffer_size > 0);
        messages.resize(buffer_size);
    }

    std::vector<LogMessageHandle> InMemoryTarget::getLogMessages() const
    {
        std::vector<LogMessageHandle> result{};
        for (uint32_t i = 0; i < message_count; i++)
        {
            uint32_t message_idx = (oldest_message_index + i) % messages.size();
            result.push_back(messages[message_idx]);
        }
        return result;
    }

    void InMemoryTarget::apply(const LogMessageHandle& message)
    {
        if (message_count < messages.size())
        {
            messages[message_count] = message;
            message_count++;
        } else
        {
            messages[oldest_message_index] = message;
            oldest_message_index = (oldest_message_index + 1) % messages.size();
        }
    }
} // Logging
