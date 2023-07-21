#pragma once

#include <queue>

#include <SFML/Window/Event.hpp>

#include "data/data.event.h"
#include "gui.input.h"

namespace Gui
{
	class InputSystem
	{
		using InputQueue = std::queue<Input*>;

		public:
            static InputSystem& GetInstance()
            {
                static InputSystem instance;
                return instance;
            };

            InputSystem(const InputSystem&) = delete;
            InputSystem& operator = (const InputSystem&) = delete;

            Input& GetNextInput();
            void RemoveNextInput();
            bool HasInputs() const;

            void OnRun();

            static void DispatchEventToInput(Data::Event& event);

        private:
            InputSystem() {};

            InputQueue inputQueue;
	};
}