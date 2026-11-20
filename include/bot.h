// Minimal skeleton of the bot structure. The competitive logic is private.
#pragma once

#include <array>
#include <cstdint>

namespace bot {

constexpr int kVision = 8;              // tiles each unit can see
constexpr int kSharedBytes = 8;         // team-wide shared memory
constexpr int64_t kFuelPerTurn = 100000;

struct Pos {
    int x = 0, y = 0;
};

// The only channel between units: 8 bytes for the whole match.
struct SharedMemory {
    std::array<uint8_t, kSharedBytes> bytes{};
};

enum class Intent : uint8_t { Farm, Fight, Retreat, Bank };

struct View;  // what one unit can see this turn

class Unit {
public:
    explicit Unit(int id) : id_(id) {}
    void take_turn(const View& view, SharedMemory& shared);

private:
    Intent decide(const View& view, const SharedMemory& shared) const;
    void act(Intent intent, const View& view);

    int id_;
};

}  // namespace bot
