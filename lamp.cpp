#include "lamp.hpp"
#include <stdio.h>

Lamp::Lamp() {
  mCharge = MAX_CHARGE;
  mDrainRate = 5;
  mIsDrained = false;
}

int Lamp::getCharge() { return mCharge; }

bool Lamp::isDrained() { return mIsDrained; }

void Lamp::pump() {
  if (!mIsDrained) {
    mCharge = (mCharge + PUMP_AMOUNT >= MAX_CHARGE) ? MAX_CHARGE
                                                    : mCharge + PUMP_AMOUNT;
  }
}

void Lamp::drain() {
  mCharge -= mDrainRate;
  if (mCharge <= 0) {
    mIsDrained = true;
  }
}

void Lamp::increaseDrainRate(int increment) {
  mDrainRate += increment;
  printf("lamp.drainRate: %d\n", mDrainRate);
}
