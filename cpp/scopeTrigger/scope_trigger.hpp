#ifndef SCOPE_TRIGGER_H
#define SCOPE_TRIGGER_H

#include <functional>

class scope_trigger final
{
public:
    scope_trigger() noexcept = default;

    template<class TAction>
    scope_trigger(TAction&& action)
    {
        set_action(std::forward<TAction>(action));
    }

    scope_trigger(scope_trigger&& other) noexcept
    {
        *this = std::move(other);
    }

    ~scope_trigger()
    {
        if (enabled())
            m_action();
    }

    scope_trigger& operator=(scope_trigger&& other) noexcept
    {
        m_action = std::move(other.m_action);

        return *this;
    }

    bool enabled() const
    {
        return bool{ m_action };
    }

    template<class TAction>
    void set_action(TAction&& action)
    {
        m_action = std::forward<TAction>(action);
    }

    void disable()
    {
        set_action(nullptr);
    }

private:
    scope_trigger(scope_trigger const&) = delete;

    scope_trigger& operator=(scope_trigger const&) = delete;

private:
    std::function<void(void)> m_action;
};


#endif // SCOPE_TRIGGER_H
