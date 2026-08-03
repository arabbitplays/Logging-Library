#ifndef DESKTOP_MANAGER_TARGET_HPP
#define DESKTOP_MANAGER_TARGET_HPP
#include <logging/messages/LogMessage.hpp>
#include <logging/rules/FilterRule.hpp>
#include <logging/rules/FilterRuleEvaluator.hpp>
#include <vector>

namespace Logging
{
    class Target
    {
        friend class LogConfigurationBuilder;

    public:
        Target() = default;
        virtual ~Target() = default;

        void log(const LogMessageHandle& message);

    protected:
        bool appliesTo(const LogMessageHandle& message);
        virtual void apply(const LogMessageHandle& message) = 0;

    private:
        void addRule(const FilterRuleHandle& rule);

        FilterRuleEvaluator rule_evaluator{};
        std::vector<FilterRuleHandle> rules;
    };

    using TargetHandle = std::shared_ptr<Target>;
} // namespace Logging

#endif // DESKTOP_MANAGER_TARGET_HPP