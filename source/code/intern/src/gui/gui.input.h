#pragma once

#include <SFML/Window/Keyboard.hpp>

namespace Gui
{
	class Input
	{
		public:
			struct KeyInput
			{
				sf::Keyboard::Key code;
			};

			enum InputType
			{
				KeyPressed,
				KeyReleased,
				NumberOfInputTypes
			};

			InputType type;
			KeyInput key;
	};
}