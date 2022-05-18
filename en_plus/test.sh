# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 18:36:38 by ndormoy           #+#    #+#              #
#    Updated: 2022/01/06 10:23:13 by ndormoy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

num=1000
pid=123508

while [ $num -ge 0 ]
do
  ./client $pid "-" && echo $num
  sleep .1
  ./client $pid "--" && echo $num
  sleep .1
  ./client $pid "---" && echo $num
  sleep .1
  ./client $pid "----" && echo $num
  sleep .1
  ./client $pid "---" && echo $num
  sleep .1
  ./client $pid "--" && echo $num
  sleep .1
  ((num -= 6))
done