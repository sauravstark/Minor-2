#ifndef SPRITE_SHEET_HPP
#define SPRITE_SHEET_HPP

#include "..//..//Datatypes/Vec.hpp"
#define SubSprite vec<4>

namespace SpriteSheet {
	namespace Enemy {
		const SubSprite floating_1				= { 00.0f * 0.0625f, 15.0f * 0.0625f, 01.0f * 0.0625f, 16.0f * 0.0625f };
		const SubSprite floating_2				= { 01.0f * 0.0625f, 15.0f * 0.0625f, 02.0f * 0.0625f, 16.0f * 0.0625f };
		const SubSprite floating_3				= { 02.0f * 0.0625f, 15.0f * 0.0625f, 03.0f * 0.0625f, 16.0f * 0.0625f };
		const SubSprite floating_4				= { 03.0f * 0.0625f, 15.0f * 0.0625f, 04.0f * 0.0625f, 16.0f * 0.0625f };
		const SubSprite flying_1				= { 00.0f * 0.0625f, 14.0f * 0.0625f, 01.0f * 0.0625f, 15.0f * 0.0625f };
		const SubSprite flying_2				= { 01.0f * 0.0625f, 14.0f * 0.0625f, 02.0f * 0.0625f, 15.0f * 0.0625f };
		const SubSprite flying_3				= { 02.0f * 0.0625f, 14.0f * 0.0625f, 03.0f * 0.0625f, 15.0f * 0.0625f };
		const SubSprite flying_4				= { 03.0f * 0.0625f, 14.0f * 0.0625f, 04.0f * 0.0625f, 15.0f * 0.0625f };
		const SubSprite flying_alt_1			= { 00.0f * 0.0625f, 13.0f * 0.0625f, 01.0f * 0.0625f, 14.0f * 0.0625f };
		const SubSprite flying_alt_2			= { 01.0f * 0.0625f, 13.0f * 0.0625f, 02.0f * 0.0625f, 14.0f * 0.0625f };
		const SubSprite flying_alt_3			= { 02.0f * 0.0625f, 13.0f * 0.0625f, 03.0f * 0.0625f, 14.0f * 0.0625f };
		const SubSprite flying_alt_4			= { 03.0f * 0.0625f, 13.0f * 0.0625f, 04.0f * 0.0625f, 14.0f * 0.0625f };
		const SubSprite spikey_1				= { 00.0f * 0.0625f, 12.0f * 0.0625f, 01.0f * 0.0625f, 13.0f * 0.0625f };
		const SubSprite spikey_2				= { 01.0f * 0.0625f, 12.0f * 0.0625f, 02.0f * 0.0625f, 13.0f * 0.0625f };
		const SubSprite spikey_3				= { 02.0f * 0.0625f, 12.0f * 0.0625f, 03.0f * 0.0625f, 13.0f * 0.0625f };
		const SubSprite spikey_4				= { 03.0f * 0.0625f, 12.0f * 0.0625f, 04.0f * 0.0625f, 13.0f * 0.0625f };
		const SubSprite swimming_1				= { 00.0f * 0.0625f, 11.0f * 0.0625f, 01.0f * 0.0625f, 12.0f * 0.0625f };
		const SubSprite swimming_2				= { 01.0f * 0.0625f, 11.0f * 0.0625f, 02.0f * 0.0625f, 12.0f * 0.0625f };
		const SubSprite swimming_3				= { 02.0f * 0.0625f, 11.0f * 0.0625f, 03.0f * 0.0625f, 12.0f * 0.0625f };
		const SubSprite swimming_4				= { 03.0f * 0.0625f, 11.0f * 0.0625f, 04.0f * 0.0625f, 12.0f * 0.0625f };
		const SubSprite walking_1				= { 00.0f * 0.0625f, 10.0f * 0.0625f, 01.0f * 0.0625f, 11.0f * 0.0625f };
		const SubSprite walking_2				= { 01.0f * 0.0625f, 10.0f * 0.0625f, 02.0f * 0.0625f, 11.0f * 0.0625f };
		const SubSprite walking_3				= { 02.0f * 0.0625f, 10.0f * 0.0625f, 03.0f * 0.0625f, 11.0f * 0.0625f };
		const SubSprite walking_4				= { 03.0f * 0.0625f, 10.0f * 0.0625f, 04.0f * 0.0625f, 11.0f * 0.0625f };
	}

	namespace Player {
	namespace Blue {
		const SubSprite dead					= { 04.0f * 0.0625f, 15.0f * 0.0625f, 05.0f * 0.0625f, 16.0f * 0.0625f };
		const SubSprite duck					= { 05.0f * 0.0625f, 15.0f * 0.0625f, 06.0f * 0.0625f, 16.0f * 0.0625f };
		const SubSprite fall					= { 06.0f * 0.0625f, 15.0f * 0.0625f, 07.0f * 0.0625f, 16.0f * 0.0625f };
		const SubSprite hit						= { 04.0f * 0.0625f, 14.0f * 0.0625f, 05.0f * 0.0625f, 15.0f * 0.0625f };
		const SubSprite roll					= { 05.0f * 0.0625f, 14.0f * 0.0625f, 06.0f * 0.0625f, 15.0f * 0.0625f };
		const SubSprite stand					= { 06.0f * 0.0625f, 14.0f * 0.0625f, 07.0f * 0.0625f, 15.0f * 0.0625f };
		const SubSprite swim_1					= { 04.0f * 0.0625f, 13.0f * 0.0625f, 05.0f * 0.0625f, 14.0f * 0.0625f };
		const SubSprite swim_2					= { 05.0f * 0.0625f, 13.0f * 0.0625f, 06.0f * 0.0625f, 14.0f * 0.0625f };
		const SubSprite switch_1				= { 06.0f * 0.0625f, 13.0f * 0.0625f, 07.0f * 0.0625f, 14.0f * 0.0625f };
		const SubSprite switch_2				= { 04.0f * 0.0625f, 12.0f * 0.0625f, 05.0f * 0.0625f, 13.0f * 0.0625f };
		const SubSprite up_1					= { 05.0f * 0.0625f, 12.0f * 0.0625f, 06.0f * 0.0625f, 13.0f * 0.0625f };
		const SubSprite up_2					= { 06.0f * 0.0625f, 12.0f * 0.0625f, 07.0f * 0.0625f, 13.0f * 0.0625f };
		const SubSprite up_3					= { 04.0f * 0.0625f, 11.0f * 0.0625f, 05.0f * 0.0625f, 12.0f * 0.0625f };
		const SubSprite walk_1					= { 05.0f * 0.0625f, 11.0f * 0.0625f, 06.0f * 0.0625f, 12.0f * 0.0625f };
		const SubSprite walk_2					= { 06.0f * 0.0625f, 11.0f * 0.0625f, 07.0f * 0.0625f, 12.0f * 0.0625f };
		const SubSprite walk_3					= { 04.0f * 0.0625f, 10.0f * 0.0625f, 05.0f * 0.0625f, 11.0f * 0.0625f };
		const SubSprite walk_4					= { 05.0f * 0.0625f, 10.0f * 0.0625f, 06.0f * 0.0625f, 11.0f * 0.0625f };
		const SubSprite walk_5					= { 06.0f * 0.0625f, 10.0f * 0.0625f, 07.0f * 0.0625f, 11.0f * 0.0625f };
	}
	namespace Green {
		const SubSprite dead					= { 07.0f * 0.0625f, 15.0f * 0.0625f, 08.0f * 0.0625f, 16.0f * 0.0625f };
		const SubSprite duck					= { 08.0f * 0.0625f, 15.0f * 0.0625f, 09.0f * 0.0625f, 16.0f * 0.0625f };
		const SubSprite fall					= { 09.0f * 0.0625f, 15.0f * 0.0625f, 10.0f * 0.0625f, 16.0f * 0.0625f };
		const SubSprite hit						= { 07.0f * 0.0625f, 14.0f * 0.0625f, 08.0f * 0.0625f, 15.0f * 0.0625f };
		const SubSprite roll					= { 08.0f * 0.0625f, 14.0f * 0.0625f, 09.0f * 0.0625f, 15.0f * 0.0625f };
		const SubSprite stand					= { 09.0f * 0.0625f, 14.0f * 0.0625f, 10.0f * 0.0625f, 15.0f * 0.0625f };
		const SubSprite swim_1					= { 07.0f * 0.0625f, 13.0f * 0.0625f, 08.0f * 0.0625f, 14.0f * 0.0625f };
		const SubSprite swim_2					= { 08.0f * 0.0625f, 13.0f * 0.0625f, 09.0f * 0.0625f, 14.0f * 0.0625f };
		const SubSprite switch_1				= { 09.0f * 0.0625f, 13.0f * 0.0625f, 10.0f * 0.0625f, 14.0f * 0.0625f };
		const SubSprite switch_2				= { 07.0f * 0.0625f, 12.0f * 0.0625f, 08.0f * 0.0625f, 13.0f * 0.0625f };
		const SubSprite up_1					= { 08.0f * 0.0625f, 12.0f * 0.0625f, 09.0f * 0.0625f, 13.0f * 0.0625f };
		const SubSprite up_2					= { 09.0f * 0.0625f, 12.0f * 0.0625f, 10.0f * 0.0625f, 13.0f * 0.0625f };
		const SubSprite up_3					= { 07.0f * 0.0625f, 11.0f * 0.0625f, 08.0f * 0.0625f, 12.0f * 0.0625f };
		const SubSprite walk_1					= { 08.0f * 0.0625f, 11.0f * 0.0625f, 09.0f * 0.0625f, 12.0f * 0.0625f };
		const SubSprite walk_2					= { 09.0f * 0.0625f, 11.0f * 0.0625f, 10.0f * 0.0625f, 12.0f * 0.0625f };
		const SubSprite walk_3					= { 07.0f * 0.0625f, 10.0f * 0.0625f, 08.0f * 0.0625f, 11.0f * 0.0625f };
		const SubSprite walk_4					= { 08.0f * 0.0625f, 10.0f * 0.0625f, 09.0f * 0.0625f, 11.0f * 0.0625f };
		const SubSprite walk_5					= { 09.0f * 0.0625f, 10.0f * 0.0625f, 10.0f * 0.0625f, 11.0f * 0.0625f };		
	}	
	namespace Grey {
		const SubSprite dead					= { 10.0f * 0.0625f, 15.0f * 0.0625f, 11.0f * 0.0625f, 16.0f * 0.0625f };
		const SubSprite duck					= { 11.0f * 0.0625f, 15.0f * 0.0625f, 12.0f * 0.0625f, 16.0f * 0.0625f };
		const SubSprite fall					= { 12.0f * 0.0625f, 15.0f * 0.0625f, 13.0f * 0.0625f, 16.0f * 0.0625f };
		const SubSprite hit						= { 10.0f * 0.0625f, 14.0f * 0.0625f, 11.0f * 0.0625f, 15.0f * 0.0625f };
		const SubSprite roll					= { 11.0f * 0.0625f, 14.0f * 0.0625f, 12.0f * 0.0625f, 15.0f * 0.0625f };
		const SubSprite stand					= { 12.0f * 0.0625f, 14.0f * 0.0625f, 13.0f * 0.0625f, 15.0f * 0.0625f };
		const SubSprite swim_1					= { 10.0f * 0.0625f, 13.0f * 0.0625f, 11.0f * 0.0625f, 14.0f * 0.0625f };
		const SubSprite swim_2					= { 11.0f * 0.0625f, 13.0f * 0.0625f, 12.0f * 0.0625f, 14.0f * 0.0625f };
		const SubSprite switch_1				= { 12.0f * 0.0625f, 13.0f * 0.0625f, 13.0f * 0.0625f, 14.0f * 0.0625f };
		const SubSprite switch_2				= { 10.0f * 0.0625f, 12.0f * 0.0625f, 11.0f * 0.0625f, 13.0f * 0.0625f };
		const SubSprite up_1					= { 11.0f * 0.0625f, 12.0f * 0.0625f, 12.0f * 0.0625f, 13.0f * 0.0625f };
		const SubSprite up_2					= { 12.0f * 0.0625f, 12.0f * 0.0625f, 13.0f * 0.0625f, 13.0f * 0.0625f };
		const SubSprite up_3					= { 10.0f * 0.0625f, 11.0f * 0.0625f, 11.0f * 0.0625f, 12.0f * 0.0625f };
		const SubSprite walk_1					= { 11.0f * 0.0625f, 11.0f * 0.0625f, 12.0f * 0.0625f, 12.0f * 0.0625f };
		const SubSprite walk_2					= { 12.0f * 0.0625f, 11.0f * 0.0625f, 13.0f * 0.0625f, 12.0f * 0.0625f };
		const SubSprite walk_3					= { 10.0f * 0.0625f, 10.0f * 0.0625f, 11.0f * 0.0625f, 11.0f * 0.0625f };
		const SubSprite walk_4					= { 11.0f * 0.0625f, 10.0f * 0.0625f, 12.0f * 0.0625f, 11.0f * 0.0625f };
		const SubSprite walk_5					= { 12.0f * 0.0625f, 10.0f * 0.0625f, 13.0f * 0.0625f, 11.0f * 0.0625f };
	}
	namespace Red {
		const SubSprite red_dead				= { 13.0f * 0.0625f, 15.0f * 0.0625f, 14.0f * 0.0625f, 16.0f * 0.0625f };
		const SubSprite red_duck				= { 14.0f * 0.0625f, 15.0f * 0.0625f, 15.0f * 0.0625f, 16.0f * 0.0625f };
		const SubSprite red_fall				= { 15.0f * 0.0625f, 15.0f * 0.0625f, 16.0f * 0.0625f, 16.0f * 0.0625f };
		const SubSprite red_hit					= { 13.0f * 0.0625f, 14.0f * 0.0625f, 14.0f * 0.0625f, 15.0f * 0.0625f };
		const SubSprite red_roll				= { 14.0f * 0.0625f, 14.0f * 0.0625f, 15.0f * 0.0625f, 15.0f * 0.0625f };
		const SubSprite red_stand				= { 15.0f * 0.0625f, 14.0f * 0.0625f, 16.0f * 0.0625f, 15.0f * 0.0625f };
		const SubSprite red_swim_1				= { 13.0f * 0.0625f, 13.0f * 0.0625f, 14.0f * 0.0625f, 14.0f * 0.0625f };
		const SubSprite red_swim_2				= { 14.0f * 0.0625f, 13.0f * 0.0625f, 15.0f * 0.0625f, 14.0f * 0.0625f };
		const SubSprite red_switch_1			= { 15.0f * 0.0625f, 13.0f * 0.0625f, 16.0f * 0.0625f, 14.0f * 0.0625f };
		const SubSprite red_switch_2			= { 13.0f * 0.0625f, 12.0f * 0.0625f, 14.0f * 0.0625f, 13.0f * 0.0625f };
		const SubSprite red_up_1				= { 14.0f * 0.0625f, 12.0f * 0.0625f, 15.0f * 0.0625f, 13.0f * 0.0625f };
		const SubSprite red_up_2				= { 15.0f * 0.0625f, 12.0f * 0.0625f, 16.0f * 0.0625f, 13.0f * 0.0625f };
		const SubSprite red_up_3				= { 13.0f * 0.0625f, 11.0f * 0.0625f, 14.0f * 0.0625f, 12.0f * 0.0625f };
		const SubSprite red_walk_1				= { 14.0f * 0.0625f, 11.0f * 0.0625f, 15.0f * 0.0625f, 12.0f * 0.0625f };
		const SubSprite red_walk_2				= { 15.0f * 0.0625f, 11.0f * 0.0625f, 16.0f * 0.0625f, 12.0f * 0.0625f };
		const SubSprite red_walk_3				= { 13.0f * 0.0625f, 10.0f * 0.0625f, 14.0f * 0.0625f, 11.0f * 0.0625f };
		const SubSprite red_walk_4				= { 14.0f * 0.0625f, 10.0f * 0.0625f, 15.0f * 0.0625f, 11.0f * 0.0625f };
		const SubSprite red_walk_5				= { 15.0f * 0.0625f, 10.0f * 0.0625f, 16.0f * 0.0625f, 11.0f * 0.0625f };
	}
	}
	
	namespace Item {
		const SubSprite crystal_blue			= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite crystal_green			= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite crystal_red				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite crystal_yellow			= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite crystal_outline			= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite gem_blue				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite gem_green				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite gem_red					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite gem_yellow				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite gem_outline				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite jewel_blue				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite jewel_green				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite jewel_red				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite jewel_yellow			= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite jewel_outline			= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite disc_green				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite disc_red				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite disc_outline			= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite disc_outline_alt		= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite key_green				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite key_red					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite key_outline				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite puzzle_green			= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite puzzle_red				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite puzzle_outline			= { 0.0f, 0.0f, 1.0f, 1.0f };
	}

	namespace Other {
	namespace Block {
		const SubSprite brown					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite green					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite grey					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite red						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite broken_brown			= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite broken_grey				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite key_green				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite key_red					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite lock_green				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite lock_red				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite puzzle_green			= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite puzzle_red				= { 0.0f, 0.0f, 1.0f, 1.0f };
	}
	namespace Button {
		const SubSprite button_floor			= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite button_green			= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite button_red				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite button_pressed_floor	= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite button_pressed_green	= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite button_pressed_red		= { 0.0f, 0.0f, 1.0f, 1.0f };
	}
	namespace Door {
		const SubSprite green					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite red						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite lock_green				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite lock_red				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite top_green				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite top_red					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite open					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite open_top				= { 0.0f, 0.0f, 1.0f, 1.0f };
	}
	namespace Fence {
		const SubSprite regular					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite broken					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite left					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite mid						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite open					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite right					= { 0.0f, 0.0f, 1.0f, 1.0f };
	}
	namespace Flag {
		const SubSprite down_green				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite down_red				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite up_green				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite up_red					= { 0.0f, 0.0f, 1.0f, 1.0f };
	}
	namespace Fluid {
		const SubSprite blue					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite brown					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite green					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite red						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite top_blue				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite top_brown				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite top_green				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite top_red					= { 0.0f, 0.0f, 1.0f, 1.0f };
	}
	namespace Ladder {
		const SubSprite narrow_mid				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite narrow_top				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite wide_mid				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite wide_top				= { 0.0f, 0.0f, 1.0f, 1.0f };
	}
	namespace Lock {
		const SubSprite green					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite red						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite bottom_green			= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite bottom_red				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite left_green				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite left_red				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite lock_green				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite lock_red				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite mid_green				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite mid_red					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite right_green				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite right_red				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite top_green				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite top_red					= { 0.0f, 0.0f, 1.0f, 1.0f };
	}
	namespace Plant {
		const SubSprite blue_1					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite blue_2					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite blue_3					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite blue_4					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite blue_5					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite blue_6					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite green_1					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite green_2					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite green_3					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite green_4					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite green_5					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite green_6					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite red_1					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite red_2					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite red_3					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite red_4					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite red_5					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite red_6					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite bottom_1				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite bottom_2				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite dark_1					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite dark_2					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite dark_3					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite dark_4					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite dark_5					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite dark_6					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite leaves_1				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite leaves_2				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite stem_corner_left		= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite stem_corner_right		= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite stem_cross				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite stem_t_left				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite stem_t_right			= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite stem_horizontal			= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite stem_vertical			= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite thorns_horizontal		= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite thorns_vertical			= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite top_blue				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite top_leaves				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite top_red					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite top_yellow				= { 0.0f, 0.0f, 1.0f, 1.0f };
	}
	namespace Sign {
		const SubSprite arrow					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite arrow_up				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite arrow_down				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite arrow_left				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite arrow_right				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite arrow_top_left			= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite arrow_top_right			= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite arrow_bottom_left		= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite arrow_bottom_right		= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite post					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite large					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite small					= { 0.0f, 0.0f, 1.0f, 1.0f };
	}
	namespace Spike {
		const SubSprite high					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite low						= { 0.0f, 0.0f, 1.0f, 1.0f };
	}
	namespace Switch {
		const SubSprite left_green				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite left_red				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite mid_green				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite mid_red					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite right_green				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite right_red				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite off_green				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite off_red					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite on_green				= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite on_red					= { 0.0f, 0.0f, 1.0f, 1.0f };
	}
	namespace Vine {
		const SubSprite regular					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite bottom					= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite bottom_alt				= { 0.0f, 0.0f, 1.0f, 1.0f };
	}
	}

	namespace Tile{
	namespace Blue {
		const SubSprite _01						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _02						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _03						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _04						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _05						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _06						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _07						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _08						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _09						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _10						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _11						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _12						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _13						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _14						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _15						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _16						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _17						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _18						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _19						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _20						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _21						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _22						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _23						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _24						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _25						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _26						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _27						= { 0.0f, 0.0f, 1.0f, 1.0f };
	}
	namespace Brown {
		const SubSprite _01						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _02						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _03						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _04						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _05						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _06						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _07						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _08						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _09						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _10						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _11						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _12						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _13						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _14						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _15						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _16						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _17						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _18						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _19						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _20						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _21						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _22						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _23						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _24						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _25						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _26						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _27						= { 0.0f, 0.0f, 1.0f, 1.0f };
	}
	namespace Green {
		const SubSprite _01						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _02						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _03						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _04						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _05						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _06						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _07						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _08						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _09						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _10						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _11						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _12						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _13						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _14						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _15						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _16						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _17						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _18						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _19						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _20						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _21						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _22						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _23						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _24						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _25						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _26						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _27						= { 0.0f, 0.0f, 1.0f, 1.0f };
	}
	namespace Yellow {
		const SubSprite _01						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _02						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _03						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _04						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _05						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _06						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _07						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _08						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _09						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _10						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _11						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _12						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _13						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _14						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _15						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _16						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _17						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _18						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _19						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _20						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _21						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _22						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _23						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _24						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _25						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _26						= { 0.0f, 0.0f, 1.0f, 1.0f };
		const SubSprite _27						= { 0.0f, 0.0f, 1.0f, 1.0f };
	}
	}
}

#endif // !SPRITE_SHEET_HPP