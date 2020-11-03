#include ".h"

vector<vector<Action>> ::sAction = {
	{ {Action::E, 0x0000},},
};

vector<vector<StatusId>> ::sGoto = {
	{},
};

vector<Reduce> ::sReduce = {
};

unordered_map <StatusId, string> ::sStatusToUnitName = {
	{ 0, "$"},
};

unordered_map<int, TerminalId> ::sWordTypeToId = {
	{ '\0', 0},
};

