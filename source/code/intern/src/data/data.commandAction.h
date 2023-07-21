#pragma once

namespace Data
{
	struct CommandAction
	{
		enum Enum
		{
			MoveRight,
			MoveRightAndJump,
			MoveLeft,
			MoveLeftAndJump,
			Jump,
			NumberOfActions,
			Undefined = -1
		};
	};
}