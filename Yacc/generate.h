#ifndef GENERATE_H
#define GENERATE_H

#include <memory>
#include <unordered_map>
#include <vector>

#include "item.h"
#include "status.h"
#include "grammar.h"
#include "unit.h"
#include "lalr.h"

using std::string;
using std::unordered_map;
using std::vector;
using std::weak_ptr;
using std::shared_ptr;

class YaccGenerate {
public:
	static YaccGenerate& getInstance() {
		static YaccGenerate sInstance;
		return sInstance;
	}

	void addStartUnit(weak_ptr<Unit> start);

	void addUnit(const string& unitName);
	bool hasUnit(const string& unitName) { return mNameToUnits.find(unitName) != mNameToUnits.end(); }
	shared_ptr<Unit>& getUnit(const string& unitName) { return mNameToUnits[unitName]; }

	shared_ptr<Unit>& getStartUnit() { return getUnit(StartUnit); }
	shared_ptr<Unit>& getEndUnit() { return getUnit(EndUnit); }

	LALR calculate();
	bool hasDeadCircleGrammar();

private:
	YaccGenerate();

	unordered_map<string, shared_ptr<Unit>> mNameToUnits;
	vector<shared_ptr<Unit>> mUnits;
	vector<Status> mStatus;

	const static string StartUnit;
	const static string EndUnit;

	// void optimizeReduce(LALR& lalr);
	
	bool hasDeadCircleGrammarDFS();
	unordered_map<string, bool> mCheckCircleFlag;
};

#endif
