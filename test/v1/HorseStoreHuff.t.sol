// SPDX-License-Identifier: GPL-3.0-only
pragma solidity 0.8.20;

import {IHorseStore} from '../../src/HorseStoreV1/IHorseStore.sol';
import {Base_TestV1} from "./Base_TestV1.t.sol";
import {HuffDeployer} from "foundry-huff/HuffDeployer.sol";

contract HorsesStoreHuff is Base_TestV1 {
    string public constant HORSE_STORE_HUFF_PATH = "HorseStoreV1/HorseStore";

    function setUp() public override {
        horseStore = IHorseStore(HuffDeployer.config().deploy(HORSE_STORE_HUFF_PATH));
    }
}