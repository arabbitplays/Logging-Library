#ifndef LOGGING_LIBRARY_INMEMORYTARGET_HPP
#define LOGGING_LIBRARY_INMEMORYTARGET_HPP
#include <logging/targets/Target.hpp>

namespace Logging
{
    class InMemoryTarget : public Target
    {
    public:
        explicit InMemoryTarget(uint32_t buffer_size);
        ~InMemoryTarget() override = default;

        std::vector<LogMessageHandle> getLogMessages() const;

    protected:
        void apply(const LogMessageHandle& message) override;

    private:
        std::vector<LogMessageHandle> messages{};
        uint32_t oldest_message_index = 0;
        uint32_t message_count = 0;
    };
} // Logging

#endif //LOGGING_LIBRARY_INMEMORYTARGET_HPP
