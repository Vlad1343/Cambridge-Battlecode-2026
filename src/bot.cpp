// Minimal skeleton of one unit's turn. The competitive logic is private.
#include "bot.h"

namespace bot {

struct View {
    Pos self;
    int hp = 0;
    int carried_gems = 0;
    int enemies_near = 0;
    int allies_near = 0;
};

void Unit::take_turn(const View& view, SharedMemory& shared) {
    // Every unit runs its own copy of this code and sees only its own view.
    const Intent intent = decide(view, shared);
    act(intent, view);
}

Intent Unit::decide(const View& view, const SharedMemory&) const {
    if (view.enemies_near > view.allies_near) return Intent::Retreat;
    if (view.carried_gems > 0) return Intent::Bank;
    if (view.enemies_near > 0) return Intent::Fight;
    return Intent::Farm;
}

void Unit::act(Intent, const View&) {
    // Pathfinding, fight evaluation and banking live here in the real bot,
    // each planned against the 100,000 fuel per turn budget.
}

}  // namespace bot
