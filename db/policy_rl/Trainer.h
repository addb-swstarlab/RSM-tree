/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Trainer.h
 * Author: wonki
 *
 * Created on January 31, 2020, 4:58 PM
 */
#pragma once

#include <ExperienceReplay.h>

class Trainer {
  public:
    int64_t batch_size = 4;
    double gamma = 0.99;
    int64_t frame_id = 0;
    std::vector<double> PreviousAction;
    ExperienceReplay buffer;
    std::vector<double> PrevState;
    torch::Tensor PrevStateTensor;
    std::vector<double> NewState; 
  
    Trainer(uint64_t capacity) : buffer(capacity){};
    virtual ~Trainer(){}
    virtual std::vector<double> act(std::vector<double> state) {
      std::cout << "Trainer act function" << std::endl;
      return std::vector<double>();
    }
    virtual void learn() {}
    
};