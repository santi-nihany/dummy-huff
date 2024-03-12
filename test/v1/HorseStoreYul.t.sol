// SPDX-License-Identifier: GPL-3.0-only
pragma solidity 0.8.20;

import {Base_TestV1} from "./Base_TestV1.t.sol";
import {HorseStoreYul} from "../../src/HorseStoreV1/HorseStoreYul.sol";
import {IHorseStore} from "../../src/HorseStoreV1/IHorseStore.sol";


contract HorsesStoreYul is Base_TestV1 {
    function setUp() public override  {
        horseStore = IHorseStore(address(new HorseStoreYul()));
    }
}