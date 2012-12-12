/*
 * Copyright (c) 2012, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <gtest/gtest.h>

#include "base_local_planner/line_iterator.h"

TEST( LineIterator, south )
{
  base_local_planner::LineIterator line( 1, 2, 1, 4 );
  EXPECT_EQ( true, line.isValid() );
  EXPECT_EQ( 1, line.getX() );
  EXPECT_EQ( 2, line.getY() );
  line.advance();
  EXPECT_EQ( true, line.isValid() );
  EXPECT_EQ( 1, line.getX() );
  EXPECT_EQ( 3, line.getY() );
  line.advance();
  EXPECT_EQ( true, line.isValid() );
  EXPECT_EQ( 1, line.getX() );
  EXPECT_EQ( 4, line.getY() );
  line.advance();
  EXPECT_EQ( false, line.isValid() );
}

TEST( LineIterator, north_north_west )
{
  base_local_planner::LineIterator line( 0, 0, -2, -4 );
  EXPECT_EQ( true, line.isValid() );
  EXPECT_EQ( 0, line.getX() );
  EXPECT_EQ( 0, line.getY() );
  line.advance();
  EXPECT_EQ( true, line.isValid() );
  EXPECT_EQ( -1, line.getX() );
  EXPECT_EQ( -1, line.getY() );
  line.advance();
  EXPECT_EQ( true, line.isValid() );
  EXPECT_EQ( -1, line.getX() );
  EXPECT_EQ( -2, line.getY() );
  line.advance();
  EXPECT_EQ( true, line.isValid() );
  EXPECT_EQ( -2, line.getX() );
  EXPECT_EQ( -3, line.getY() );
  line.advance();
  EXPECT_EQ( true, line.isValid() );
  EXPECT_EQ( -2, line.getX() );
  EXPECT_EQ( -4, line.getY() );
  line.advance();
  EXPECT_EQ( false, line.isValid() );
}

int main( int argc, char **argv ) {
  testing::InitGoogleTest( &argc, argv );
  return RUN_ALL_TESTS();
}