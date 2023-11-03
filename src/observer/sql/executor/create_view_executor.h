//
// Created by leauny on 23-11-2.
//

#pragma once

#include "common/rc.h"

class SQLStageEvent;

class CreateViewExecutor
{
public:
  CreateViewExecutor() = default;
  virtual ~CreateViewExecutor() = default;

  RC execute(SQLStageEvent *sql_event);
};