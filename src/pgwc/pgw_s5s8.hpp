/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

/*! \file s5s8.hpp
   \author  Lionel GAUTHIER
   \date 2018
   \email: lionel.gauthier@eurecom.fr
*/

#ifndef FILE_PGW_SS5S8_HPP_SEEN
#define FILE_PGW_SS5S8_HPP_SEEN

#include "gtpv2c.hpp"
#include "itti_msg_s5s8.hpp"

#include <thread>

namespace oai::cn::nf::pgwc {

class pgw_s5s8 : public proto::gtpv2c::gtpv2c_stack {
private:
  std::thread::id                      thread_id;
  std::thread                          thread;

  void handle_receive_gtpv2c_msg(proto::gtpv2c::gtpv2c_msg& msg, const boost::asio::ip::udp::endpoint& remote_endpoint);
  void handle_receive_create_session_request(proto::gtpv2c::gtpv2c_msg& msg, const boost::asio::ip::udp::endpoint& remote_endpoint );
  void handle_receive_delete_session_request(proto::gtpv2c::gtpv2c_msg& msg, const boost::asio::ip::udp::endpoint& remote_endpoint);
  void handle_receive_modify_bearer_request(proto::gtpv2c::gtpv2c_msg& msg, const boost::asio::ip::udp::endpoint& remote_endpoint);
  void handle_receive_release_access_bearers_request(proto::gtpv2c::gtpv2c_msg& msg, const boost::asio::ip::udp::endpoint& remote_endpoint);

public:
  pgw_s5s8();
  pgw_s5s8(pgw_s5s8 const&)    = delete;
  void operator=(pgw_s5s8 const&)     = delete;

  void handle_receive(char* recv_buffer, const std::size_t bytes_transferred, boost::asio::ip::udp::endpoint& remote_endpoint);

  void send_msg(core::itti::itti_s5s8_create_session_response& m);
  void send_msg(core::itti::itti_s5s8_delete_session_response& m);
  void send_msg(core::itti::itti_s5s8_modify_bearer_response& m);
  void send_msg(core::itti::itti_s5s8_release_access_bearers_response& m);

  void time_out_itti_event(const uint32_t timer_id);
};
}
#endif /* FILE_PGW_SS5S8_HPP_SEEN */
