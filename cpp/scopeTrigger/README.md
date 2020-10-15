# `scope_trigger`

The `scope_trigger` class is a simple way of setting actions that will be executed when the execution flow exits the scope where those actions are.

## Constructors

### `scope_trigger() noexcept`

Builds a `scope_trigger` object in an empty state (no action assigned).

### `scope_trigger(scope_trigger&& other) noexcept`

Builds a `scope_trigger` object from `other`, moving `other`'s action to this object and leaving `other` in an empty state.

### `template<class TAction> scope_trigger(TAction&& action) noexcept`

Builds a `scope_trigger` object assigning `action` as this instance's triggered action.

## Overloaded Operators

### `scope_trigger& operator=(scope_trigger&& other) noexcept`

Assigns `other` to this object, moving `other`'s action to this object and leaving `other` in an empty state.

## Methods

### `bool enabled() const`

Returns `true` if this `scope_trigger` object has an assigned action. Returns `false` otherwise.

### `template<class TAction> void set_action(TAction&& action)`

Assigns `action` as the new triggered action of this `scope_trigger` object.

### `void disable()`

Assigns no action to this `scope_trigger` object, leaving it in an empty state.
