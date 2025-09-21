/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 23:35:37 by ykamboua          #+#    #+#             */
/*   Updated: 2025/09/20 23:12:26 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


class Serializer
{
	private:
		Serializer();
		Serializer(Serializer& other);
		Serializer& operator=(Serializer& other);
		~Serializer();
	public:
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
}
