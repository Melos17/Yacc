
E	{EUnit}	:	E '+' T	{EplusT}
			|	T		{TtoE}
			;

T	{TUnit}	:	T '*' F	{TmultiF}
			|	F		{FtoT}
			;

F	{FUnit}	:	'(' E ')'	{EtoF}
			|	IDENTIFIER	{IDtoF}
			;

%%

struct EUnit : Unit {
	EUnit(int value) {
		this->value = value;
	}
	int value;
};
struct TUnit : Unit {
	TUnit(int value) {
		this->value = value;
	}
	int value;
};
struct FUnit : Unit {
	FUnit(int value) {
		this->value = value;
	}
	int value;
};

EUnit* EplusT(EUnit unit1, TerminalUnit unit2, TUnit unit3) {
	std::cout << __FUNCTION__ << ":" << unit1.value + unit3.value << std::endl;
	return new EUnit(unit1.value + unit3.value);
}
EUnit* TtoE(TUnit unit) {
	std::cout << __FUNCTION__ << ":" << unit.value << std::endl;
	return new EUnit(unit.value);
}

TUnit* TmultiF(TUnit unit1, TerminalUnit unit2, FUnit unit3) {
	std::cout << __FUNCTION__ << ":" << unit1.value * unit3.value << std::endl;
	return new TUnit(unit1.value * unit3.value);
}
TUnit* FtoT(FUnit unit) {
	std::cout << __FUNCTION__ << ":" << unit.value << std::endl;
	return new TUnit(unit.value);
}

FUnit* EtoF(TerminalUnit unit1, EUnit unit2, TerminalUnit unit3) {
	std::cout << __FUNCTION__ << ":" << unit2.value << std::endl;
	return new FUnit(unit2.value);
}
FUnit* IDtoF(TerminalUnit unit) {
	std::cout << __FUNCTION__ << ":" << std::stoi(unit.word) << std::endl;
	return new FUnit(std::stoi(unit.word));
}