#include <iostream>
#include <assert.h>

#include "gui.inputSystem.h"

#include "data/data.eventSystem.h"
#include "data/data.commandAction.h"

namespace Gui
{
	void InputSystem::DispatchEventToInput(Data::Event& event)
	{
		Input& input = *(new Input());

		input.key.code = sf::Keyboard::Key(event.GetData());

		InputSystem::GetInstance().inputQueue.push(&input);
	}

    Input& InputSystem::GetNextInput()
    {
        assert(!inputQueue.empty());

        return *inputQueue.front();
    }

    void InputSystem::RemoveNextInput()
    {
        assert(!inputQueue.empty());

        Input* input = inputQueue.front();

        delete input;

        inputQueue.pop();
    }

    bool InputSystem::HasInputs() const
    {
        return !inputQueue.empty();
    }

    void InputSystem::OnRun()
    {
        Input current;

        while (HasInputs())
        {
            current = GetNextInput();

            if (current.key.code == sf::Keyboard::Key::Up)
            {
                Data::EventSystem::GetInstance().FireEvent(Data::EventType::PressedUp);
            }
            else if (current.key.code == sf::Keyboard::Key::Down)
            {
				Data::EventSystem::GetInstance().FireEvent(Data::EventType::PressedDown);
			}
            else if (current.key.code == sf::Keyboard::Key::Escape)
            {
                Data::EventSystem::GetInstance().FireEvent(Data::EventType::PressedEscape);
            }
            else if(current.key.code == sf::Keyboard::Key::Enter)
            {
                Data::EventSystem::GetInstance().FireEvent(Data::EventType::PressedEnter);
            }
            else if (current.key.code == sf::Keyboard::Key::Space && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            {
                Data::EventSystem::GetInstance().FireEvent(Data::EventType::DispatchInputToCommand, Data::CommandAction::MoveRightAndJump);
            }
			else if (current.key.code == sf::Keyboard::Key::Space && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			{
                Data::EventSystem::GetInstance().FireEvent(Data::EventType::DispatchInputToCommand, Data::CommandAction::MoveLeftAndJump);
			}
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			{
				Data::EventSystem::GetInstance().FireEvent(Data::EventType::DispatchInputToCommand, Data::CommandAction::MoveRight);
			}
			else if (current.key.code == sf::Keyboard::Key::Left)
			{
				Data::EventSystem::GetInstance().FireEvent(Data::EventType::DispatchInputToCommand, Data::CommandAction::MoveLeft);
			}
			else if (current.key.code == sf::Keyboard::Key::Space)
			{
				Data::EventSystem::GetInstance().FireEvent(Data::EventType::DispatchInputToCommand, Data::CommandAction::Jump);
			}

            RemoveNextInput();
        }
    }
}