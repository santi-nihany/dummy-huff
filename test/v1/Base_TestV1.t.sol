// SPDX-License-Identifier: GPL-3.0-only
pragma solidity 0.8.20;

import {HorseStore} from "../../src/HorseStoreV1/HorseStore.sol";
import{Test, console2} from "forge-std/Test.sol";

abstract contract Base_TestV1 is Test {
    HorseStore public horseStore;

    function setUp() public virtual {
        horseStore = new HorseStore();
    }

    function testReadValue() public {
        uint256 initValue = horseStore.readNumberOfHorses();
        assertEq(initValue,0,"Initial value should be 0");
    }

    function testUpdateValue() public {
        horseStore.updateHorseNumber(5);
        uint256 updatedValue = horseStore.readNumberOfHorses();
        assertEq(updatedValue,5,"Updated value should be 5");
    }
}