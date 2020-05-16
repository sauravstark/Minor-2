#ifndef SPRITE_SHEET_HPP
#define SPRITE_SHEET_HPP

#include "..//..//Datatypes/Vec.hpp"
#define SubSprite vec<4>

namespace SpriteSheet {
	namespace Player {
		const SubSprite destroyer		= { 0.0f * 0.125f, 0.0f * 0.125f, 2.0f * 0.125f, 2.0f * 0.125f };
		const SubSprite carrier			= { 2.0f * 0.125f, 0.0f * 0.125f, 4.0f * 0.125f, 2.0f * 0.125f };
		const SubSprite cargoship		= { 4.0f * 0.125f, 0.0f * 0.125f, 5.0f * 0.125f, 2.0f * 0.125f };
		const SubSprite shuttle			= { 5.0f * 0.125f, 0.0f * 0.125f, 6.0f * 0.125f, 2.0f * 0.125f };
		const SubSprite cruiser			= { 6.0f * 0.125f, 0.0f * 0.125f, 7.0f * 0.125f, 2.0f * 0.125f };
		const SubSprite red_fighter7	= { 0.0f * 0.125f, 2.0f * 0.125f, 2.0f * 0.125f, 4.0f * 0.125f };
		const SubSprite red_fighter8	= { 2.0f * 0.125f, 2.0f * 0.125f, 4.0f * 0.125f, 4.0f * 0.125f };
		const SubSprite red_fighter9	= { 4.0f * 0.125f, 2.0f * 0.125f, 6.0f * 0.125f, 4.0f * 0.125f };
		const SubSprite tribase1		= { 6.0f * 0.125f, 2.0f * 0.125f, 8.0f * 0.125f, 4.0f * 0.125f };
		const SubSprite red_fighter4	= { 0.0f * 0.125f, 4.0f * 0.125f, 2.0f * 0.125f, 6.0f * 0.125f };
		const SubSprite red_fighter5	= { 2.0f * 0.125f, 4.0f * 0.125f, 4.0f * 0.125f, 6.0f * 0.125f };
		const SubSprite red_fighter6	= { 4.0f * 0.125f, 4.0f * 0.125f, 6.0f * 0.125f, 6.0f * 0.125f };
		const SubSprite tribase2		= { 6.0f * 0.125f, 4.0f * 0.125f, 8.0f * 0.125f, 6.0f * 0.125f };
		const SubSprite red_fighter1	= { 0.0f * 0.125f, 6.0f * 0.125f, 2.0f * 0.125f, 8.0f * 0.125f };
		const SubSprite red_fighter2	= { 2.0f * 0.125f, 6.0f * 0.125f, 4.0f * 0.125f, 8.0f * 0.125f };
		const SubSprite red_fighter3	= { 4.0f * 0.125f, 6.0f * 0.125f, 6.0f * 0.125f, 8.0f * 0.125f };
		const SubSprite tribase3		= { 6.0f * 0.125f, 6.0f * 0.125f, 8.0f * 0.125f, 8.0f * 0.125f };
	}

	namespace Bullet {
	namespace Orange {
		const SubSprite _1						= { 0.0f * 0.125f, 0.0f * 0.125f, 1.0f * 0.125f, 1.0f * 0.125f };
		const SubSprite _2						= { 1.0f * 0.125f, 0.0f * 0.125f, 2.0f * 0.125f, 1.0f * 0.125f };
		const SubSprite _3						= { 2.0f * 0.125f, 0.0f * 0.125f, 3.0f * 0.125f, 1.0f * 0.125f };
		const SubSprite _4						= { 3.0f * 0.125f, 0.0f * 0.125f, 4.0f * 0.125f, 1.0f * 0.125f };
		const SubSprite _5						= { 4.0f * 0.125f, 0.0f * 0.125f, 5.0f * 0.125f, 1.0f * 0.125f };
		const SubSprite _6						= { 5.0f * 0.125f, 0.0f * 0.125f, 6.0f * 0.125f, 1.0f * 0.125f };
		const SubSprite _7						= { 6.0f * 0.125f, 0.0f * 0.125f, 7.0f * 0.125f, 1.0f * 0.125f };
		const SubSprite _8						= { 7.0f * 0.125f, 0.0f * 0.125f, 8.0f * 0.125f, 1.0f * 0.125f };
	}
	namespace Red {
		const SubSprite _1						= { 0.0f * 0.125f, 1.0f * 0.125f, 1.0f * 0.125f, 2.0f * 0.125f };
		const SubSprite _2						= { 1.0f * 0.125f, 1.0f * 0.125f, 2.0f * 0.125f, 2.0f * 0.125f };
		const SubSprite _3						= { 2.0f * 0.125f, 1.0f * 0.125f, 3.0f * 0.125f, 2.0f * 0.125f };
		const SubSprite _4						= { 3.0f * 0.125f, 1.0f * 0.125f, 4.0f * 0.125f, 2.0f * 0.125f };
		const SubSprite _5						= { 4.0f * 0.125f, 1.0f * 0.125f, 5.0f * 0.125f, 2.0f * 0.125f };
		const SubSprite _6						= { 5.0f * 0.125f, 1.0f * 0.125f, 6.0f * 0.125f, 2.0f * 0.125f };
		const SubSprite _7						= { 6.0f * 0.125f, 1.0f * 0.125f, 7.0f * 0.125f, 2.0f * 0.125f };
		const SubSprite _8						= { 7.0f * 0.125f, 1.0f * 0.125f, 8.0f * 0.125f, 2.0f * 0.125f };
	}	
	namespace Blue {
		const SubSprite _1						= { 0.0f * 0.125f, 2.0f * 0.125f, 1.0f * 0.125f, 3.0f * 0.125f };
		const SubSprite _2						= { 1.0f * 0.125f, 2.0f * 0.125f, 2.0f * 0.125f, 3.0f * 0.125f };
		const SubSprite _3						= { 2.0f * 0.125f, 2.0f * 0.125f, 3.0f * 0.125f, 3.0f * 0.125f };
		const SubSprite _4						= { 3.0f * 0.125f, 2.0f * 0.125f, 4.0f * 0.125f, 3.0f * 0.125f };
		const SubSprite _5						= { 4.0f * 0.125f, 2.0f * 0.125f, 5.0f * 0.125f, 3.0f * 0.125f };
		const SubSprite _6						= { 5.0f * 0.125f, 2.0f * 0.125f, 6.0f * 0.125f, 3.0f * 0.125f };
		const SubSprite _7						= { 6.0f * 0.125f, 2.0f * 0.125f, 7.0f * 0.125f, 3.0f * 0.125f };
		const SubSprite _8						= { 7.0f * 0.125f, 2.0f * 0.125f, 8.0f * 0.125f, 3.0f * 0.125f };
	}
	}

	namespace Explosion_Small {
	namespace Orange {
		const SubSprite _1						= { 0.0f * 0.125f, 3.0f * 0.125f, 1.0f * 0.125f, 4.0f * 0.125f };
		const SubSprite _2						= { 1.0f * 0.125f, 3.0f * 0.125f, 2.0f * 0.125f, 4.0f * 0.125f };
		const SubSprite _3						= { 2.0f * 0.125f, 3.0f * 0.125f, 3.0f * 0.125f, 4.0f * 0.125f };
		const SubSprite _4						= { 3.0f * 0.125f, 3.0f * 0.125f, 4.0f * 0.125f, 4.0f * 0.125f };
		const SubSprite _5						= { 4.0f * 0.125f, 3.0f * 0.125f, 5.0f * 0.125f, 4.0f * 0.125f };
		const SubSprite _6						= { 5.0f * 0.125f, 3.0f * 0.125f, 6.0f * 0.125f, 4.0f * 0.125f };
		const SubSprite _7						= { 6.0f * 0.125f, 3.0f * 0.125f, 7.0f * 0.125f, 4.0f * 0.125f };
		const SubSprite _8						= { 7.0f * 0.125f, 3.0f * 0.125f, 8.0f * 0.125f, 4.0f * 0.125f };
	}
	namespace Red {
		const SubSprite _1						= { 0.0f * 0.125f, 4.0f * 0.125f, 1.0f * 0.125f, 5.0f * 0.125f };
		const SubSprite _2						= { 1.0f * 0.125f, 4.0f * 0.125f, 2.0f * 0.125f, 5.0f * 0.125f };
		const SubSprite _3						= { 2.0f * 0.125f, 4.0f * 0.125f, 3.0f * 0.125f, 5.0f * 0.125f };
		const SubSprite _4						= { 3.0f * 0.125f, 4.0f * 0.125f, 4.0f * 0.125f, 5.0f * 0.125f };
		const SubSprite _5						= { 4.0f * 0.125f, 4.0f * 0.125f, 5.0f * 0.125f, 5.0f * 0.125f };
		const SubSprite _6						= { 5.0f * 0.125f, 4.0f * 0.125f, 6.0f * 0.125f, 5.0f * 0.125f };
		const SubSprite _7						= { 6.0f * 0.125f, 4.0f * 0.125f, 7.0f * 0.125f, 5.0f * 0.125f };
		const SubSprite _8						= { 7.0f * 0.125f, 4.0f * 0.125f, 8.0f * 0.125f, 5.0f * 0.125f };
	}	
	namespace Blue {
		const SubSprite _1						= { 0.0f * 0.125f, 5.0f * 0.125f, 1.0f * 0.125f, 6.0f * 0.125f };
		const SubSprite _2						= { 1.0f * 0.125f, 5.0f * 0.125f, 2.0f * 0.125f, 6.0f * 0.125f };
		const SubSprite _3						= { 2.0f * 0.125f, 5.0f * 0.125f, 3.0f * 0.125f, 6.0f * 0.125f };
		const SubSprite _4						= { 3.0f * 0.125f, 5.0f * 0.125f, 4.0f * 0.125f, 6.0f * 0.125f };
		const SubSprite _5						= { 4.0f * 0.125f, 5.0f * 0.125f, 5.0f * 0.125f, 6.0f * 0.125f };
		const SubSprite _6						= { 5.0f * 0.125f, 5.0f * 0.125f, 6.0f * 0.125f, 6.0f * 0.125f };
		const SubSprite _7						= { 6.0f * 0.125f, 5.0f * 0.125f, 7.0f * 0.125f, 6.0f * 0.125f };
		const SubSprite _8						= { 7.0f * 0.125f, 5.0f * 0.125f, 8.0f * 0.125f, 6.0f * 0.125f };
	}
	}

	namespace Explosion_Big {
	namespace Orange {
		const SubSprite _1						= { 0.0f * 0.125f, 6.0f * 0.125f, 1.0f * 0.125f, 7.0f * 0.125f };
		const SubSprite _2						= { 1.0f * 0.125f, 6.0f * 0.125f, 2.0f * 0.125f, 7.0f * 0.125f };
		const SubSprite _3						= { 2.0f * 0.125f, 6.0f * 0.125f, 3.0f * 0.125f, 7.0f * 0.125f };
		const SubSprite _4						= { 3.0f * 0.125f, 6.0f * 0.125f, 4.0f * 0.125f, 7.0f * 0.125f };
		const SubSprite _5						= { 4.0f * 0.125f, 6.0f * 0.125f, 5.0f * 0.125f, 7.0f * 0.125f };
		const SubSprite _6						= { 5.0f * 0.125f, 6.0f * 0.125f, 6.0f * 0.125f, 7.0f * 0.125f };
		const SubSprite _7						= { 6.0f * 0.125f, 6.0f * 0.125f, 7.0f * 0.125f, 7.0f * 0.125f };
		const SubSprite _8						= { 7.0f * 0.125f, 6.0f * 0.125f, 8.0f * 0.125f, 7.0f * 0.125f };
	}	
	namespace Black {
		const SubSprite _1						= { 0.0f * 0.125f, 7.0f * 0.125f, 1.0f * 0.125f, 8.0f * 0.125f };
		const SubSprite _2						= { 1.0f * 0.125f, 7.0f * 0.125f, 2.0f * 0.125f, 8.0f * 0.125f };
		const SubSprite _3						= { 2.0f * 0.125f, 7.0f * 0.125f, 3.0f * 0.125f, 8.0f * 0.125f };
		const SubSprite _4						= { 3.0f * 0.125f, 7.0f * 0.125f, 4.0f * 0.125f, 8.0f * 0.125f };
		const SubSprite _5						= { 4.0f * 0.125f, 7.0f * 0.125f, 5.0f * 0.125f, 8.0f * 0.125f };
		const SubSprite _6						= { 5.0f * 0.125f, 7.0f * 0.125f, 6.0f * 0.125f, 8.0f * 0.125f };
		const SubSprite _7						= { 6.0f * 0.125f, 7.0f * 0.125f, 7.0f * 0.125f, 8.0f * 0.125f };
		const SubSprite _8						= { 7.0f * 0.125f, 7.0f * 0.125f, 8.0f * 0.125f, 8.0f * 0.125f };
	}
	}
}

#endif // !SPRITE_SHEET_HPP