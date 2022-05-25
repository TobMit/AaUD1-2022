//
// Created by Tobias on 25/05/2022.
//
#include "criterion.h"
#include "ostatneUdaje.h"

#pragma once
class CriterionVZPocet : Criterion<int> {
public:
    CriterionVZPocet(const int pIndex);

    int evaluate(const StoredData &data) override;

private:
    int index;

};

inline CriterionVZPocet::CriterionVZPocet(const int pIndex) :
    index(pIndex)
{
}

inline int CriterionVZPocet::evaluate(const StoredData &data) {
    auto ostatneData = dynamic_cast<const OstatneUdaje &>(data);
    return ostatneData.intAt(index);
}